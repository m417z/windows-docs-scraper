typedef struct _KEYBOARD_EXTENDED_ATTRIBUTES {
  UCHAR Version;
  UCHAR FormFactor;
  UCHAR KeyType;
  UCHAR PhysicalLayout;
  UCHAR VendorSpecificPhysicalLayout;
  UCHAR IETFLanguageTagIndex;
  UCHAR ImplementedInputAssistControls;
} KEYBOARD_EXTENDED_ATTRIBUTES, *PKEYBOARD_EXTENDED_ATTRIBUTES;