NTSTATUS WdfChildListCreate(
  [in]           WDFDEVICE              Device,
  [in]           PWDF_CHILD_LIST_CONFIG Config,
  [in, optional] PWDF_OBJECT_ATTRIBUTES ChildListAttributes,
  [out]          WDFCHILDLIST           *ChildList
);