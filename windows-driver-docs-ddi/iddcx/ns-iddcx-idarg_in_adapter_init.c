struct IDARG_IN_ADAPTER_INIT {
  WDFDEVICE              WdfDevice;
  IDDCX_ADAPTER_CAPS     *pCaps;
  PWDF_OBJECT_ATTRIBUTES ObjectAttributes;
};