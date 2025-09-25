typedef struct _WSDXML_ELEMENT {
  WSDXML_NODE           Node;
  WSDXML_NAME           *Name;
  WSDXML_ATTRIBUTE      *FirstAttribute;
  WSDXML_NODE           *FirstChild;
  WSDXML_PREFIX_MAPPING *PrefixMappings;
} WSDXML_ELEMENT;