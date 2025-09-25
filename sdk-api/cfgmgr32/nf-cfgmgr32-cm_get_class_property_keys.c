CMAPI CONFIGRET CM_Get_Class_Property_Keys(
  [in]            LPCGUID    ClassGUID,
  [out, optional] DEVPROPKEY *PropertyKeyArray,
  [in, out]       PULONG     PropertyKeyCount,
  [in]            ULONG      ulFlags
);