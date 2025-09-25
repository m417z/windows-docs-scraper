typedef struct _KEYBOARD_ATTRIBUTES {
  KEYBOARD_ID                   KeyboardIdentifier;
  USHORT                        KeyboardMode;
  USHORT                        NumberOfFunctionKeys;
  USHORT                        NumberOfIndicators;
  USHORT                        NumberOfKeysTotal;
  ULONG                         InputDataQueueLength;
  KEYBOARD_TYPEMATIC_PARAMETERS KeyRepeatMinimum;
  KEYBOARD_TYPEMATIC_PARAMETERS KeyRepeatMaximum;
} KEYBOARD_ATTRIBUTES, *PKEYBOARD_ATTRIBUTES;