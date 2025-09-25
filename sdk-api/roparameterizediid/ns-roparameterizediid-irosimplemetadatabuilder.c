struct IRoSimpleMetaDataBuilder {
  HRESULT SetWinRtInterface(
    GUID iid
  );
  HRESULT SetDelegate(
    GUID iid
  );
  HRESULT SetInterfaceGroupSimpleDefault(
    PCWSTR     name,
    PCWSTR     defaultInterfaceName,
    const GUID *defaultInterfaceIID
  );
  HRESULT SetInterfaceGroupParameterizedDefault(
    PCWSTR name,
    UINT32 elementCount,
    PCWSTR *defaultInterfaceNameElements
  );
  HRESULT SetRuntimeClassSimpleDefault(
    PCWSTR     name,
    PCWSTR     defaultInterfaceName,
    const GUID *defaultInterfaceIID
  );
  HRESULT SetRuntimeClassParameterizedDefault(
    PCWSTR       name,
    UINT32       elementCount,
    const PCWSTR *defaultInterfaceNameElements
  );
  HRESULT SetStruct(
    PCWSTR       name,
    UINT32       numFields,
    const PCWSTR *fieldTypeNames
  );
  HRESULT SetEnum(
    PCWSTR name,
    PCWSTR baseType
  );
  HRESULT SetParameterizedInterface(
    GUID   piid,
    UINT32 numArgs
  );
  HRESULT SetParameterizedDelegate(
    GUID   piid,
    UINT32 numArgs
  );
};