HRESULT RoRegisterForApartmentShutdown(
  [in]  IApartmentShutdown                     *callbackObject,
  [out] UINT64                                 *apartmentIdentifier,
  [out] APARTMENT_SHUTDOWN_REGISTRATION_COOKIE *regCookie
);