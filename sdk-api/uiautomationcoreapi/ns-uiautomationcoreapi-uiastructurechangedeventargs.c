struct UiaStructureChangedEventArgs {
  EventArgsType       Type;
  int                 EventId;
  StructureChangeType StructureChangeType;
  int                 *pRuntimeId;
  int                 cRuntimeIdLen;
};