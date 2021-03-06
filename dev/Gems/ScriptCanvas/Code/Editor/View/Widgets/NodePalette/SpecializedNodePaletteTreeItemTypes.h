/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include <GraphCanvas/Widgets/NodePalette/TreeItems/DraggableNodePaletteTreeItem.h>
#include "CreateNodeMimeEvent.h"

namespace ScriptCanvasEditor
{
    // <EntityRefNode>
    class CreateEntityRefNodeMimeEvent
        : public CreateNodeMimeEvent
    {
    public:
        AZ_RTTI(CreateEntityRefNodeMimeEvent, "{20CD5AF5-216E-4A41-9630-191C2803899B}", CreateNodeMimeEvent);
        AZ_CLASS_ALLOCATOR(CreateEntityRefNodeMimeEvent, AZ::SystemAllocator, 0);

        static void Reflect(AZ::ReflectContext* reflectContext);

        CreateEntityRefNodeMimeEvent() = default;
        CreateEntityRefNodeMimeEvent(const AZ::EntityId& entityId);
        ~CreateEntityRefNodeMimeEvent() = default;

    protected:
        ScriptCanvasEditor::NodeIdPair CreateNode(const AZ::EntityId& graphId) const override;

    private:
        AZ::EntityId m_entityId;
    };

    class EntityRefNodePaletteTreeItem
        : public GraphCanvas::DraggableNodePaletteTreeItem
    {
    public:
        AZ_CLASS_ALLOCATOR(EntityRefNodePaletteTreeItem, AZ::SystemAllocator, 0);
        EntityRefNodePaletteTreeItem(const QString& nodeName, const QString& iconPath);
        ~EntityRefNodePaletteTreeItem() = default;

        GraphCanvas::GraphCanvasMimeEvent* CreateMimeEvent() const override;
    };
    // </EntityRefNode>    
    
    // <CommentNode>
    class CreateCommentNodeMimeEvent
        : public SpecializedCreateNodeMimeEvent
    {
    public:
        AZ_RTTI(CreateCommentNodeMimeEvent, "{AF5BB1C0-E5CF-40B1-A037-1500C2BAC787}", SpecializedCreateNodeMimeEvent);
        AZ_CLASS_ALLOCATOR(CreateCommentNodeMimeEvent, AZ::SystemAllocator, 0);

        static void Reflect(AZ::ReflectContext* reflectContext);

        CreateCommentNodeMimeEvent() = default;
        ~CreateCommentNodeMimeEvent() = default;

        NodeIdPair ConstructNode(const AZ::EntityId& sceneId, const AZ::Vector2& scenePosition);
        bool ExecuteEvent(const AZ::Vector2& mousePosition, AZ::Vector2& sceneDropPosition, const AZ::EntityId& sceneId) override;
    };

    class CommentNodePaletteTreeItem
        : public GraphCanvas::DraggableNodePaletteTreeItem
    {
    public:
        AZ_CLASS_ALLOCATOR(CommentNodePaletteTreeItem, AZ::SystemAllocator, 0);
        CommentNodePaletteTreeItem(const QString& nodeName, const QString& iconPath);
        ~CommentNodePaletteTreeItem() = default;

        GraphCanvas::GraphCanvasMimeEvent* CreateMimeEvent() const override;
    };    
    // </CommentNode>

    // <BlockCommentNode>
    class CreateBlockCommentNodeMimeEvent
        : public SpecializedCreateNodeMimeEvent
    {
    public:
        AZ_RTTI(CreateBlockCommentNodeMimeEvent, "{FD969A58-404E-4B97-8A62-57C2B5EAC686}", SpecializedCreateNodeMimeEvent);
        AZ_CLASS_ALLOCATOR(CreateBlockCommentNodeMimeEvent, AZ::SystemAllocator, 0);

        static void Reflect(AZ::ReflectContext* reflectContext);

        CreateBlockCommentNodeMimeEvent() = default;
        ~CreateBlockCommentNodeMimeEvent() = default;

        NodeIdPair ConstructNode(const AZ::EntityId& sceneId, const AZ::Vector2& scenePosition);
        bool ExecuteEvent(const AZ::Vector2& mousePosition, AZ::Vector2& sceneDropPosition, const AZ::EntityId& sceneId) override;
    };

    class BlockCommentNodePaletteTreeItem
        : public GraphCanvas::DraggableNodePaletteTreeItem
    {
    public:
        AZ_CLASS_ALLOCATOR(BlockCommentNodePaletteTreeItem, AZ::SystemAllocator, 0);
        BlockCommentNodePaletteTreeItem(const QString& nodeName, const QString& iconPath);
        ~BlockCommentNodePaletteTreeItem() = default;

        GraphCanvas::GraphCanvasMimeEvent* CreateMimeEvent() const override;
    };
    // </BlockCommentNode>
}