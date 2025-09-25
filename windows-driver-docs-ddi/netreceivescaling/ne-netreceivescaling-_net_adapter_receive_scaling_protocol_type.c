typedef enum _NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE {
  NetAdapterReceiveScalingProtocolTypeNone = 0x00000000,
  NetAdapterReceiveScalingProtocolTypeIPv4 = 0x00000001,
  NetAdapterReceiveScalingProtocolTypeIPv4Options = 0x00000002,
  NetAdapterReceiveScalingProtocolTypeIPv6 = 0x00000004,
  NetAdapterReceiveScalingProtocolTypeIPv6Extensions = 0x00000008,
  NetAdapterReceiveScalingProtocolTypeTcp = 0x00000010,
  NetAdapterReceiveScalingProtocolTypeUdp = 0x00000020
} NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE;