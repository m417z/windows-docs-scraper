typedef struct _NDIS_QOS_CLASSIFICATION_ELEMENT {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  USHORT             ConditionSelector;
  USHORT             ConditionField;
  USHORT             ActionSelector;
  USHORT             ActionField;
} NDIS_QOS_CLASSIFICATION_ELEMENT, *PNDIS_QOS_CLASSIFICATION_ELEMENT;