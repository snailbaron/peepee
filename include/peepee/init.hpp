#pragma once

namespace pp {

struct InitializeOptions {
    bool initializeWin32Sockets = true;
    bool initializeSSL = true;
};

void initialize(const InitializeOptions& options = {});
void cleanup();

} // namespace pp
