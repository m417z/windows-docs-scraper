BOOL SNMP_FUNC_TYPE SnmpMgrGetTrap(
  [out] AsnObjectIdentifier *enterprise,
  [out] AsnNetworkAddress   *IPAddress,
  [out] AsnInteger          *genericTrap,
  [out] AsnInteger          *specificTrap,
  [out] AsnTimeticks        *timeStamp,
  [out] RFC1157VarBindList  *variableBindings
);