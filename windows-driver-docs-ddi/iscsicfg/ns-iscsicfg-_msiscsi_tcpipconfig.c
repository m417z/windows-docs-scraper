typedef struct _MSiSCSI_TCPIPConfig {
  BOOLEAN          UseLinkLocalAddress;
  BOOLEAN          EnableDHCP;
  BOOLEAN          UseDHCPForDNS;
  ULONG            IPVersions;
  ISCSI_IP_Address IpAddress;
  ISCSI_IP_Address DefaultGateway;
  ISCSI_IP_Address SubnetMask;
  ISCSI_IP_Address PreferredDNSServer;
  ISCSI_IP_Address AlternateDNSServer;
} MSiSCSI_TCPIPConfig, *PMSiSCSI_TCPIPConfig;