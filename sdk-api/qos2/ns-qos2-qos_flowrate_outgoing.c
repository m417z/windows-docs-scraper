typedef struct _QOS_FLOWRATE_OUTGOING {
  UINT64              Bandwidth;
  QOS_SHAPING         ShapingBehavior;
  QOS_FLOWRATE_REASON Reason;
} QOS_FLOWRATE_OUTGOING, *PQOS_FLOWRATE_OUTGOING;