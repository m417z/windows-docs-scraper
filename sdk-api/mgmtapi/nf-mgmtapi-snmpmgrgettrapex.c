BOOL SNMP_FUNC_TYPE SnmpMgrGetTrapEx(
  [out] AsnObjectIdentifier *enterprise,
  [out] AsnNetworkAddress   *agentAddress,
  [out] AsnNetworkAddress   *sourceAddress,
  [out] AsnInteger          *genericTrap,
  [out] AsnInteger          *specificTrap,
  [out] AsnOctetString      *community,
  [out] AsnTimeticks        *timeStamp,
  [out] RFC1157VarBindList  *variableBindings
);