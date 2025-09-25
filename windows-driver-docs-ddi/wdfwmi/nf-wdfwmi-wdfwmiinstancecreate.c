NTSTATUS WdfWmiInstanceCreate(
  [in]            WDFDEVICE                Device,
  [in]            PWDF_WMI_INSTANCE_CONFIG InstanceConfig,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES   InstanceAttributes,
  [out, optional] WDFWMIINSTANCE           *Instance
);