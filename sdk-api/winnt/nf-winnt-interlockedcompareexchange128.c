BOOLEAN InterlockedCompareExchange128(
  [in, out] LONG64 volatile *Destination,
  [in]      LONG64          ExchangeHigh,
  [in]      LONG64          ExchangeLow,
  [in, out] LONG64          *ComparandResult
);