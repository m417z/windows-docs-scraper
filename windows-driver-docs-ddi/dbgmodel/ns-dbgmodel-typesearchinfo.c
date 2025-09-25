struct TypeSearchInfo : SymbolSearchInfo {
  void     TypeSearchInfo();
  void     TypeSearchInfo(
    TypeKind searchType
  );
  TypeKind SearchType;
};