PDXGK_INITIAL_COMPONENT_STATE PdxgkInitialComponentState;

VOID PdxgkInitialComponentState(
  PVOID GraphicsDeviceHandle,
  PVOID PrivateHandle,
  ULONG ComponentIndex,
  BOOLEAN IsBlockingType,
  UINT InitialFState,
  GUID ComponentGuid,
  UINT PowerComponentMappingFlag
)
{...}