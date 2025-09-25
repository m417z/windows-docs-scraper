NTSTATUS UcxControllerCreate(
  [in]           WDFDEVICE              Device,
  [in]           PUCX_CONTROLLER_CONFIG Config,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          UCXCONTROLLER          *Controller
);