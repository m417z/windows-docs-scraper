EVT_WDF_CHILD_LIST_CREATE_DEVICE EvtWdfChildListCreateDevice;

NTSTATUS EvtWdfChildListCreateDevice(
  [in] WDFCHILDLIST ChildList,
  [in] PWDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER IdentificationDescription,
  [in] PWDFDEVICE_INIT ChildInit
)
{...}