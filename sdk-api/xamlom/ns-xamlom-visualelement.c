typedef struct VisualElement {
  InstanceHandle Handle;
  SourceInfo     SrcInfo;
  BSTR           Type;
  BSTR           Name;
  unsigned int   NumChildren;
} VisualElement;