typedef enum MetadataBit {
  None = 0,
  IsValueHandle = 0x1,
  IsPropertyReadOnly = 0x2,
  IsValueCollection = 0x4,
  IsValueCollectionReadOnly = 0x8,
  IsValueBindingExpression = 0x10,
  IsValueNull = 0x20,
  IsValueHandleAndEvaluatedValue = 0x40
} ;