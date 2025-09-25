typedef struct _UCX_ROOTHUB_CONFIG {
  ULONG                           Size;
  ULONG                           NumberOfPresentedControlUrbCallbacks;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubClearHubFeature;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubClearPortFeature;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubGetHubStatus;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubGetPortStatus;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubSetHubFeature;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubSetPortFeature;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubGetPortErrorCount;
  PFN_UCX_ROOTHUB_CONTROL_URB     EvtRootHubControlUrb;
  PFN_UCX_ROOTHUB_INTERRUPT_TX    EvtRootHubInterruptTx;
  PFN_UCX_ROOTHUB_GET_INFO        EvtRootHubGetInfo;
  PFN_UCX_ROOTHUB_GET_20PORT_INFO EvtRootHubGet20PortInfo;
  PFN_UCX_ROOTHUB_GET_30PORT_INFO EvtRootHubGet30PortInfo;
  WDF_OBJECT_ATTRIBUTES           WdfRequestAttributes;
} UCX_ROOTHUB_CONFIG, *PUCX_ROOTHUB_CONFIG;