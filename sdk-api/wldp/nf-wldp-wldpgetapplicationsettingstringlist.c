STDAPI
WldpGetApplicationSettingStringList(
    _In_ PCWSTR id, 
    _In_ PCWSTR setting, 
    _In_ SIZE_T dataCount, 
    _Out_ SIZE_T *requiredCount, 
    _Out_writes_to_opt_(*dataCount, *requiredCount) PZZWSTR result 
    );