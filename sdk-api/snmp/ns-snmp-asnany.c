typedef struct {
  BYTE  asnType;
  union {
    AsnInteger32        number;
    AsnUnsigned32       unsigned32;
    AsnCounter64        counter64;
    AsnOctetString      string;
    AsnBits             bits;
    AsnObjectIdentifier object;
    AsnSequence         sequence;
    AsnIPAddress        address;
    AsnCounter32        counter;
    AsnGauge32          gauge;
    AsnTimeticks        ticks;
    AsnOpaque           arbitrary;
  } asnValue;
} AsnAny;