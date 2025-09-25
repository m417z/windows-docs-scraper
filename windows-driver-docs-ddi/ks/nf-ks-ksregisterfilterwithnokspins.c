KSDDKAPI NTSTATUS KsRegisterFilterWithNoKSPins(
  [in]           PDEVICE_OBJECT DeviceObject,
  [in]           const GUID     *InterfaceClassGUID,
  [in]           ULONG          PinCount,
  [in]           BOOL           *PinDirection,
  [in]           KSPIN_MEDIUM   *MediumList,
  [in, optional] GUID           *CategoryList
);