typedef struct _FPGA_CONTROL_INTERFACE {
  USHORT                        Size;
  USHORT                        Version;
  PVOID                         Context;
  PINTERFACE_REFERENCE          InterfaceReference;
  PINTERFACE_DEREFERENCE        InterfaceDereference;
  PFPGA_BUS_SCAN                BusScan;
  PFPGA_CONTROL_LINK            ControlLink;
  PFPGA_CONTROL_CONFIG_SPACE    ControlConfigSpace;
  PFPGA_CONTROL_ERROR_REPORTING ControlErrorReporting;
} FPGA_CONTROL_INTERFACE, *PFPGA_CONTROL_INTERFACE;