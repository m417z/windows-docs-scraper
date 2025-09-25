typedef struct PropertyChainSource {
  InstanceHandle  Handle;
  BSTR            TargetType;
  BSTR            Name;
  BaseValueSource Source;
  SourceInfo      SrcInfo;
} PropertyChainSource;