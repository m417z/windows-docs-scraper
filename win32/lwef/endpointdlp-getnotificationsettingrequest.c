struct GetNotificationSettingRequest
{
    _Field_z_ LPCWSTR locale;
    DlpSerializedBuffer policyInfo;
    DlpActionType actionType;
    BOOLEAN isUnallowedBrowser;
    _Field_z_ LPCWSTR displayFilename;
    _Field_z_ LPCWSTR displayProcessName;
    _Field_z_ LPCWSTR jsonExtraInfo;
    DlpSerializedBuffer jsonNotification;
};