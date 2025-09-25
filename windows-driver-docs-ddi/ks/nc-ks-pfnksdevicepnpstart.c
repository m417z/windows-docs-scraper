PFNKSDEVICEPNPSTART Pfnksdevicepnpstart;

NTSTATUS Pfnksdevicepnpstart(
  [in]           PKSDEVICE Device,
  [in]           PIRP Irp,
  [in, optional] PCM_RESOURCE_LIST TranslatedResourceList,
  [in, optional] PCM_RESOURCE_LIST UntranslatedResourceList
)
{...}