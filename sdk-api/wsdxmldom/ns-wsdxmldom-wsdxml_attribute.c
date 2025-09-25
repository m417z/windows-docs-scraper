typedef struct _WSDXML_ATTRIBUTE {
  WSDXML_ELEMENT   *Element;
  WSDXML_ATTRIBUTE *Next;
  WSDXML_NAME      *Name;
  WCHAR            *Value;
} WSDXML_ATTRIBUTE;