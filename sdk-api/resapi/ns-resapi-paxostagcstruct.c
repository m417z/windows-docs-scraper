typedef struct _PaxosTagCStruct {
  unsigned __int64 __padding__PaxosTagVtable;
  unsigned __int64 __padding__NextEpochVtable;
  unsigned __int64 __padding__NextEpoch_DateTimeVtable;
  unsigned __int64 NextEpoch_DateTime_ticks;
  int              NextEpoch_Value;
  DWORD            __padding__BoundryNextEpoch;
  unsigned __int64 __padding__EpochVtable;
  unsigned __int64 __padding__Epoch_DateTimeVtable;
  unsigned __int64 Epoch_DateTime_ticks;
  int              Epoch_Value;
  DWORD            __padding__BoundryEpoch;
  int              Sequence;
  DWORD            __padding__BoundrySequence;
} PaxosTagCStruct, *PPaxosTagCStruct;