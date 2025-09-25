typedef enum _PROPERTY_FLAGS {
  PropertyStruct = 0x1,
  PropertyParamLength = 0x2,
  PropertyParamCount = 0x4,
  PropertyWBEMXmlFragment = 0x8,
  PropertyParamFixedLength = 0x10,
  PropertyParamFixedCount = 0x20,
  PropertyHasTags = 0x40,
  PropertyHasCustomSchema = 0x80
} PROPERTY_FLAGS;