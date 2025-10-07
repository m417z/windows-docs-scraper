struct AuthGroupOverrideRequest
{
    LPCWSTR filePath;
    LPCWSTR attrDetails;
    DlpActionType action;
    DlpSerializedBuffer outputBuffer;
};