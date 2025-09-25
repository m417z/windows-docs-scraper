typedef enum _STORAGE_ZONE_CONDITION {
  ZoneConditionConventional,
  ZoneConditionEmpty,
  ZoneConditionImplicitlyOpened,
  ZoneConditionExplicitlyOpened,
  ZoneConditionClosed,
  ZoneConditionReadOnly,
  ZoneConditionFull,
  ZoneConditionOffline
} STORAGE_ZONE_CONDITION, *PSTORAGE_ZONE_CONDITION;