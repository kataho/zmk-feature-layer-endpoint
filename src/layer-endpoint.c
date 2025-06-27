#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/ble.h>
#include <zmk/keymap.h>

static int bluetooth_listener_cb(const zmk_event_t *eh) {
    if (zmk_ble_active_profile_is_connected()) {
        switch (zmk_ble_active_profile_index()) {
        case 0: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P0); break;
        case 1: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P1); break;
        case 2: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P2); break;
        case 3: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P3); break;
        case 4: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P4); break;
        case 5: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P5); break;
        default: break;
        }
    }
    return 0;
}

ZMK_LISTENER(layer_endpoint_bluetooth_listener, bluetooth_listener_cb);
ZMK_SUBSCRIPTION(layer_endpoint_bluetooth_listener, zmk_ble_active_profile_changed);

extern void layer_endpoint_init_lazy(void) {
    if (zmk_ble_active_profile_is_connected()) {
        switch (zmk_ble_active_profile_index()) {
        case 0: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P0); break;
        case 1: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P1); break;
        case 2: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P2); break;
        case 3: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P3); break;
        case 4: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P4); break;
        case 5: zmk_keymap_layer_to(CONFIG_LAYER_ENDPOINT_P5); break;
        default: break;
        }
    }
}

K_THREAD_DEFINE(layer_endpoint_init_thread, 1024, layer_endpoint_init_lazy, NULL, NULL, NULL,
                K_LOWEST_APPLICATION_THREAD_PRIO, 0, 200);
