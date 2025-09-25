SHSTDAPI SHPropStgWriteMultiple(
  [in]                IPropertyStorage  *pps,
  [in, out, optional] UINT              *puCodePage,
                      ULONG             cpspec,
  [in]                PROPSPEC const [] rgpspec,
  [in, out]           PROPVARIANT []    rgvar,
                      PROPID            propidNameFirst
);