typedef struct _BTH_LE_GATT_DESCRIPTOR_VALUE {
  BTH_LE_GATT_DESCRIPTOR_TYPE DescriptorType;
  BTH_LE_UUID                 DescriptorUuid;
  union {
    struct {
      BOOLEAN IsReliableWriteEnabled;
      BOOLEAN IsAuxiliariesWritable;
    } CharacteristicExtendedProperties;
    struct {
      BOOLEAN IsSubscribeToNotification;
      BOOLEAN IsSubscribeToIndication;
    } ClientCharacteristicConfiguration;
    struct {
      BOOLEAN IsBroadcast;
    } ServerCharacteristicConfiguration;
    struct {
      UCHAR       Format;
      UCHAR       Exponent;
      BTH_LE_UUID Unit;
      UCHAR       NameSpace;
      BTH_LE_UUID Description;
    } CharacteristicFormat;
  };
  ULONG                       DataSize;
#if ...
  UCHAR                       *Data[];
#else
  UCHAR                       Data[1];
#endif
} BTH_LE_GATT_DESCRIPTOR_VALUE, *PBTH_LE_GATT_DESCRIPTOR_VALUE;