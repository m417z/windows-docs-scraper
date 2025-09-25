struct UiaPropertyChangedEventArgs {
  EventArgsType Type;
  int           EventId;
  PROPERTYID    PropertyId;
  VARIANT       OldValue;
  VARIANT       NewValue;
};