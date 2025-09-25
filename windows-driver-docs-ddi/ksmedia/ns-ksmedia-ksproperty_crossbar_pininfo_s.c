typedef struct {
  KSPROPERTY     Property;
  KSPIN_DATAFLOW Direction;
  ULONG          Index;
  ULONG          PinType;
  ULONG          RelatedPinIndex;
  KSPIN_MEDIUM   Medium;
} KSPROPERTY_CROSSBAR_PININFO_S, *PKSPROPERTY_CROSSBAR_PININFO_S;