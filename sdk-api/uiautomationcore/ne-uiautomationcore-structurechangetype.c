typedef enum StructureChangeType {
  StructureChangeType_ChildAdded = 0,
  StructureChangeType_ChildRemoved,
  StructureChangeType_ChildrenInvalidated,
  StructureChangeType_ChildrenBulkAdded,
  StructureChangeType_ChildrenBulkRemoved,
  StructureChangeType_ChildrenReordered
} ;