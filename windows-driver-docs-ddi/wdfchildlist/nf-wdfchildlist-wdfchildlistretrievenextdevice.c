NTSTATUS WdfChildListRetrieveNextDevice(
  [in]      WDFCHILDLIST             ChildList,
  [in]      PWDF_CHILD_LIST_ITERATOR Iterator,
  [out]     WDFDEVICE                *Device,
  [in, out] PWDF_CHILD_RETRIEVE_INFO Info
);