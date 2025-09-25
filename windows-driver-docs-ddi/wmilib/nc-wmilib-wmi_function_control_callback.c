WMI_FUNCTION_CONTROL_CALLBACK WmiFunctionControlCallback;

NTSTATUS WmiFunctionControlCallback(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PIRP Irp,
  [in] ULONG GuidIndex,
  [in] WMIENABLEDISABLECONTROL Function,
  [in] BOOLEAN Enable
)
{...}