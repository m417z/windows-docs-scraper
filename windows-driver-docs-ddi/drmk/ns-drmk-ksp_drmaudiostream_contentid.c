typedef struct {
  KSPROPERTY                         Property;
  PVOID                              Context;
  PFNDRMADDCONTENTHANDLERS           DrmAddContentHandlers;
  PFNDRMCREATECONTENTMIXED           DrmCreateContentMixed;
  PFNDRMDESTROYCONTENT               DrmDestroyContent;
  PFNDRMFORWARDCONTENTTODEVICEOBJECT DrmForwardContentToDeviceObject;
  PFNDRMFORWARDCONTENTTOFILEOBJECT   DrmForwardContentToFileObject;
  PFNDRMFORWARDCONTENTTOINTERFACE    DrmForwardContentToInterface;
  PFNDRMGETCONTENTRIGHTS             DrmGetContentRights;
} KSP_DRMAUDIOSTREAM_CONTENTID, *PKSP_DRMAUDIOSTREAM_CONTENTID;