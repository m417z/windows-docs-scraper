EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtUrsDeviceFilterResourceRequirements;

NTSTATUS EvtUrsDeviceFilterResourceRequirements(
  [in] WDFDEVICE Device,
  [in] WDFIORESREQLIST IoResourceRequirementsList,
  [in] URSIORESLIST HostRoleResources,
  [in] URSIORESLIST FunctionRoleResources
)
{...}