typedef struct _KSDEVICE {
  const KSDEVICE_DESCRIPTOR *Descriptor;
  KSOBJECT_BAG              Bag;
  PVOID                     Context;
  PDEVICE_OBJECT            FunctionalDeviceObject;
  PDEVICE_OBJECT            PhysicalDeviceObject;
  PDEVICE_OBJECT            NextDeviceObject;
  BOOLEAN                   Started;
  SYSTEM_POWER_STATE        SystemPowerState;
  DEVICE_POWER_STATE        DevicePowerState;
} KSDEVICE, *PKSDEVICE;