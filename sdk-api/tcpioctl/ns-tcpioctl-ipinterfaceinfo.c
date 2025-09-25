typedef struct IPInterfaceInfo {
  ulong iii_flags;
  ulong iii_mtu;
  ulong iii_speed;
  ulong iii_addrlength;
  uchar iii_addr[1];
} IPInterfaceInfo;