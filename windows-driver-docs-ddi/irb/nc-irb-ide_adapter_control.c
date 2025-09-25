IDE_ADAPTER_CONTROL IdeAdapterControl;

BOOLEAN IdeAdapterControl(
  [in]      PVOID ControllerExtension,
  [in]      IDE_CONTROL_ACTION ControlAction,
  [in, out] PVOID Parameters
)
{...}