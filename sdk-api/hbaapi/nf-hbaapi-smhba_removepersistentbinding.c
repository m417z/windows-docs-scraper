HBA_STATUS HBA_API SMHBA_RemovePersistentBinding(
  HBA_HANDLE          Handle,
  HBA_WWN             HbaPortWWN,
  HBA_WWN             DomainPortWWN,
  const SMHBA_BINDING *Binding
);