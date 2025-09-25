NTSTATUS FwpsConstructIpHeaderForTransportPacket0(
  [in, out]      NET_BUFFER_LIST  *netBufferList,
                 ULONG            headerIncludeHeaderLength,
  [in]           ADDRESS_FAMILY   addressFamily,
  [in]           const UCHAR      *sourceAddress,
  [in]           const UCHAR      *remoteAddress,
  [in]           IPPROTO          nextProtocol,
  [in, optional] UINT64           endpointHandle,
  [in, optional] const WSACMSGHDR *controlData,
  [in]           ULONG            controlDataLength,
  [in]           UINT32           flags,
                 PVOID            reserved,
  [in, optional] IF_INDEX         interfaceIndex,
  [in, optional] IF_INDEX         subInterfaceIndex
);