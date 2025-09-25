struct Location {
  ULONG64    HostDefined;
  ULONG64    Offset;
  void       Location();
  void       Location(
    ULONG64 virtualAddress
  );
  void       Location(
    const Location & src
  );
  Location & operator=(
    const Location & src
  );
  Location & operator=(
    ULONG64 virtualAddress
  );
  bool       operator==(
    const Location & rhs
  );
  bool       operator!=(
    const Location & rhs
  );
  Location & operator+=(
    LONG64 offset
  );
  Location & operator-=(
    LONG64 offset
  );
  Location   operator+(
    LONG64 offset
  );
  Location   operator-(
    LONG64 offset
  );
  ULONG64    GetOffset();
  bool       IsVirtualAddress();
};