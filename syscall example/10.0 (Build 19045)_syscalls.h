// ==============================================================================
// Windows Syscall Table Dumper
// Dumped by: ellii
// Windows Version: 10.0 (Build 19045)
// Dumped at: 2025-11-13 20:31:02
// Source: C:\Windows\System32\ntdll.dll
// Total Syscalls: 472
// ==============================================================================

#pragma once

#include <cstdint>
#include <array>

namespace syscalls {

    namespace idx {

        inline constexpr uintptr_t nt_access_check = 0x0; // #0
        inline constexpr uintptr_t nt_worker_factory_worker_ready = 0x1; // #1
        inline constexpr uintptr_t nt_accept_connect_port = 0x2; // #2
        inline constexpr uintptr_t nt_map_user_physical_pages_scatter = 0x3; // #3
        inline constexpr uintptr_t nt_wait_for_single_object = 0x4; // #4
        inline constexpr uintptr_t nt_callback_return = 0x5; // #5
        inline constexpr uintptr_t nt_read_file = 0x6; // #6
        inline constexpr uintptr_t nt_device_io_control_file = 0x7; // #7
        inline constexpr uintptr_t nt_write_file = 0x8; // #8
        inline constexpr uintptr_t nt_remove_io_completion = 0x9; // #9
        inline constexpr uintptr_t nt_release_semaphore = 0xa; // #10
        inline constexpr uintptr_t nt_reply_wait_receive_port = 0xb; // #11
        inline constexpr uintptr_t nt_reply_port = 0xc; // #12
        inline constexpr uintptr_t nt_set_information_thread = 0xd; // #13
        inline constexpr uintptr_t nt_set_event = 0xe; // #14
        inline constexpr uintptr_t nt_close = 0xf; // #15
        inline constexpr uintptr_t nt_query_object = 0x10; // #16
        inline constexpr uintptr_t nt_query_information_file = 0x11; // #17
        inline constexpr uintptr_t nt_open_key = 0x12; // #18
        inline constexpr uintptr_t nt_enumerate_value_key = 0x13; // #19
        inline constexpr uintptr_t nt_find_atom = 0x14; // #20
        inline constexpr uintptr_t nt_query_default_locale = 0x15; // #21
        inline constexpr uintptr_t nt_query_key = 0x16; // #22
        inline constexpr uintptr_t nt_query_value_key = 0x17; // #23
        inline constexpr uintptr_t nt_allocate_virtual_memory = 0x18; // #24
        inline constexpr uintptr_t nt_query_information_process = 0x19; // #25
        inline constexpr uintptr_t nt_wait_for_multiple_objects32 = 0x1a; // #26
        inline constexpr uintptr_t nt_write_file_gather = 0x1b; // #27
        inline constexpr uintptr_t nt_set_information_process = 0x1c; // #28
        inline constexpr uintptr_t nt_create_key = 0x1d; // #29
        inline constexpr uintptr_t nt_free_virtual_memory = 0x1e; // #30
        inline constexpr uintptr_t nt_impersonate_client_of_port = 0x1f; // #31
        inline constexpr uintptr_t nt_release_mutant = 0x20; // #32
        inline constexpr uintptr_t nt_query_information_token = 0x21; // #33
        inline constexpr uintptr_t nt_request_wait_reply_port = 0x22; // #34
        inline constexpr uintptr_t nt_query_virtual_memory = 0x23; // #35
        inline constexpr uintptr_t nt_open_thread_token = 0x24; // #36
        inline constexpr uintptr_t nt_query_information_thread = 0x25; // #37
        inline constexpr uintptr_t nt_open_process = 0x26; // #38
        inline constexpr uintptr_t nt_set_information_file = 0x27; // #39
        inline constexpr uintptr_t nt_map_view_of_section = 0x28; // #40
        inline constexpr uintptr_t nt_access_check_and_audit_alarm = 0x29; // #41
        inline constexpr uintptr_t nt_unmap_view_of_section = 0x2a; // #42
        inline constexpr uintptr_t nt_reply_wait_receive_port_ex = 0x2b; // #43
        inline constexpr uintptr_t nt_terminate_process = 0x2c; // #44
        inline constexpr uintptr_t nt_set_event_boost_priority = 0x2d; // #45
        inline constexpr uintptr_t nt_read_file_scatter = 0x2e; // #46
        inline constexpr uintptr_t nt_open_thread_token_ex = 0x2f; // #47
        inline constexpr uintptr_t nt_open_process_token_ex = 0x30; // #48
        inline constexpr uintptr_t nt_query_performance_counter = 0x31; // #49
        inline constexpr uintptr_t nt_enumerate_key = 0x32; // #50
        inline constexpr uintptr_t nt_open_file = 0x33; // #51
        inline constexpr uintptr_t nt_delay_execution = 0x34; // #52
        inline constexpr uintptr_t nt_query_directory_file = 0x35; // #53
        inline constexpr uintptr_t nt_query_system_information = 0x36; // #54
        inline constexpr uintptr_t nt_open_section = 0x37; // #55
        inline constexpr uintptr_t nt_query_timer = 0x38; // #56
        inline constexpr uintptr_t nt_fs_control_file = 0x39; // #57
        inline constexpr uintptr_t nt_write_virtual_memory = 0x3a; // #58
        inline constexpr uintptr_t nt_close_object_audit_alarm = 0x3b; // #59
        inline constexpr uintptr_t nt_duplicate_object = 0x3c; // #60
        inline constexpr uintptr_t nt_query_attributes_file = 0x3d; // #61
        inline constexpr uintptr_t nt_clear_event = 0x3e; // #62
        inline constexpr uintptr_t nt_read_virtual_memory = 0x3f; // #63
        inline constexpr uintptr_t nt_open_event = 0x40; // #64
        inline constexpr uintptr_t nt_adjust_privileges_token = 0x41; // #65
        inline constexpr uintptr_t nt_duplicate_token = 0x42; // #66
        inline constexpr uintptr_t nt_continue = 0x43; // #67
        inline constexpr uintptr_t nt_query_default_u_i_language = 0x44; // #68
        inline constexpr uintptr_t nt_queue_apc_thread = 0x45; // #69
        inline constexpr uintptr_t nt_yield_execution = 0x46; // #70
        inline constexpr uintptr_t nt_add_atom = 0x47; // #71
        inline constexpr uintptr_t nt_create_event = 0x48; // #72
        inline constexpr uintptr_t nt_query_volume_information_file = 0x49; // #73
        inline constexpr uintptr_t nt_create_section = 0x4a; // #74
        inline constexpr uintptr_t nt_flush_buffers_file = 0x4b; // #75
        inline constexpr uintptr_t nt_apphelp_cache_control = 0x4c; // #76
        inline constexpr uintptr_t nt_create_process_ex = 0x4d; // #77
        inline constexpr uintptr_t nt_create_thread = 0x4e; // #78
        inline constexpr uintptr_t nt_is_process_in_job = 0x4f; // #79
        inline constexpr uintptr_t nt_protect_virtual_memory = 0x50; // #80
        inline constexpr uintptr_t nt_query_section = 0x51; // #81
        inline constexpr uintptr_t nt_resume_thread = 0x52; // #82
        inline constexpr uintptr_t nt_terminate_thread = 0x53; // #83
        inline constexpr uintptr_t nt_read_request_data = 0x54; // #84
        inline constexpr uintptr_t nt_create_file = 0x55; // #85
        inline constexpr uintptr_t nt_query_event = 0x56; // #86
        inline constexpr uintptr_t nt_write_request_data = 0x57; // #87
        inline constexpr uintptr_t nt_open_directory_object = 0x58; // #88
        inline constexpr uintptr_t nt_access_check_by_type_and_audit_alarm = 0x59; // #89
        inline constexpr uintptr_t nt_wait_for_multiple_objects = 0x5b; // #91
        inline constexpr uintptr_t nt_set_information_object = 0x5c; // #92
        inline constexpr uintptr_t nt_cancel_io_file = 0x5d; // #93
        inline constexpr uintptr_t nt_trace_event = 0x5e; // #94
        inline constexpr uintptr_t nt_power_information = 0x5f; // #95
        inline constexpr uintptr_t nt_set_value_key = 0x60; // #96
        inline constexpr uintptr_t nt_cancel_timer = 0x61; // #97
        inline constexpr uintptr_t nt_set_timer = 0x62; // #98
        inline constexpr uintptr_t nt_access_check_by_type = 0x63; // #99
        inline constexpr uintptr_t nt_access_check_by_type_result_list = 0x64; // #100
        inline constexpr uintptr_t nt_access_check_by_type_result_list_and_audit_alarm = 0x65; // #101
        inline constexpr uintptr_t nt_access_check_by_type_result_list_and_audit_alarm_by_handle = 0x66; // #102
        inline constexpr uintptr_t nt_acquire_cross_vm_mutant = 0x67; // #103
        inline constexpr uintptr_t nt_acquire_process_activity_reference = 0x68; // #104
        inline constexpr uintptr_t nt_add_atom_ex = 0x69; // #105
        inline constexpr uintptr_t nt_add_boot_entry = 0x6a; // #106
        inline constexpr uintptr_t nt_add_driver_entry = 0x6b; // #107
        inline constexpr uintptr_t nt_adjust_groups_token = 0x6c; // #108
        inline constexpr uintptr_t nt_adjust_token_claims_and_device_groups = 0x6d; // #109
        inline constexpr uintptr_t nt_alert_resume_thread = 0x6e; // #110
        inline constexpr uintptr_t nt_alert_thread = 0x6f; // #111
        inline constexpr uintptr_t nt_alert_thread_by_thread_id = 0x70; // #112
        inline constexpr uintptr_t nt_allocate_locally_unique_id = 0x71; // #113
        inline constexpr uintptr_t nt_allocate_reserve_object = 0x72; // #114
        inline constexpr uintptr_t nt_allocate_user_physical_pages = 0x73; // #115
        inline constexpr uintptr_t nt_allocate_user_physical_pages_ex = 0x74; // #116
        inline constexpr uintptr_t nt_allocate_uuids = 0x75; // #117
        inline constexpr uintptr_t nt_allocate_virtual_memory_ex = 0x76; // #118
        inline constexpr uintptr_t nt_alpc_accept_connect_port = 0x77; // #119
        inline constexpr uintptr_t nt_alpc_cancel_message = 0x78; // #120
        inline constexpr uintptr_t nt_alpc_connect_port = 0x79; // #121
        inline constexpr uintptr_t nt_alpc_connect_port_ex = 0x7a; // #122
        inline constexpr uintptr_t nt_alpc_create_port = 0x7b; // #123
        inline constexpr uintptr_t nt_alpc_create_port_section = 0x7c; // #124
        inline constexpr uintptr_t nt_alpc_create_resource_reserve = 0x7d; // #125
        inline constexpr uintptr_t nt_alpc_create_section_view = 0x7e; // #126
        inline constexpr uintptr_t nt_alpc_create_security_context = 0x7f; // #127
        inline constexpr uintptr_t nt_alpc_delete_port_section = 0x80; // #128
        inline constexpr uintptr_t nt_alpc_delete_resource_reserve = 0x81; // #129
        inline constexpr uintptr_t nt_alpc_delete_section_view = 0x82; // #130
        inline constexpr uintptr_t nt_alpc_delete_security_context = 0x83; // #131
        inline constexpr uintptr_t nt_alpc_disconnect_port = 0x84; // #132
        inline constexpr uintptr_t nt_alpc_impersonate_client_container_of_port = 0x85; // #133
        inline constexpr uintptr_t nt_alpc_impersonate_client_of_port = 0x86; // #134
        inline constexpr uintptr_t nt_alpc_open_sender_process = 0x87; // #135
        inline constexpr uintptr_t nt_alpc_open_sender_thread = 0x88; // #136
        inline constexpr uintptr_t nt_alpc_query_information = 0x89; // #137
        inline constexpr uintptr_t nt_alpc_query_information_message = 0x8a; // #138
        inline constexpr uintptr_t nt_alpc_revoke_security_context = 0x8b; // #139
        inline constexpr uintptr_t nt_alpc_send_wait_receive_port = 0x8c; // #140
        inline constexpr uintptr_t nt_alpc_set_information = 0x8d; // #141
        inline constexpr uintptr_t nt_are_mapped_files_the_same = 0x8e; // #142
        inline constexpr uintptr_t nt_assign_process_to_job_object = 0x8f; // #143
        inline constexpr uintptr_t nt_associate_wait_completion_packet = 0x90; // #144
        inline constexpr uintptr_t nt_call_enclave = 0x91; // #145
        inline constexpr uintptr_t nt_cancel_io_file_ex = 0x92; // #146
        inline constexpr uintptr_t nt_cancel_synchronous_io_file = 0x93; // #147
        inline constexpr uintptr_t nt_cancel_timer2 = 0x94; // #148
        inline constexpr uintptr_t nt_cancel_wait_completion_packet = 0x95; // #149
        inline constexpr uintptr_t nt_commit_complete = 0x96; // #150
        inline constexpr uintptr_t nt_commit_enlistment = 0x97; // #151
        inline constexpr uintptr_t nt_commit_registry_transaction = 0x98; // #152
        inline constexpr uintptr_t nt_commit_transaction = 0x99; // #153
        inline constexpr uintptr_t nt_compact_keys = 0x9a; // #154
        inline constexpr uintptr_t nt_compare_objects = 0x9b; // #155
        inline constexpr uintptr_t nt_compare_signing_levels = 0x9c; // #156
        inline constexpr uintptr_t nt_compare_tokens = 0x9d; // #157
        inline constexpr uintptr_t nt_complete_connect_port = 0x9e; // #158
        inline constexpr uintptr_t nt_compress_key = 0x9f; // #159
        inline constexpr uintptr_t nt_connect_port = 0xa0; // #160
        inline constexpr uintptr_t nt_continue_ex = 0xa1; // #161
        inline constexpr uintptr_t nt_convert_between_auxiliary_counter_and_performance_counter = 0xa2; // #162
        inline constexpr uintptr_t nt_copy_file_chunk = 0xa3; // #163
        inline constexpr uintptr_t nt_create_cross_vm_event = 0xa4; // #164
        inline constexpr uintptr_t nt_create_cross_vm_mutant = 0xa5; // #165
        inline constexpr uintptr_t nt_create_debug_object = 0xa6; // #166
        inline constexpr uintptr_t nt_create_directory_object = 0xa7; // #167
        inline constexpr uintptr_t nt_create_directory_object_ex = 0xa8; // #168
        inline constexpr uintptr_t nt_create_enclave = 0xa9; // #169
        inline constexpr uintptr_t nt_create_enlistment = 0xaa; // #170
        inline constexpr uintptr_t nt_create_event_pair = 0xab; // #171
        inline constexpr uintptr_t nt_create_i_r_timer = 0xac; // #172
        inline constexpr uintptr_t nt_create_io_completion = 0xad; // #173
        inline constexpr uintptr_t nt_create_job_object = 0xae; // #174
        inline constexpr uintptr_t nt_create_job_set = 0xaf; // #175
        inline constexpr uintptr_t nt_create_key_transacted = 0xb0; // #176
        inline constexpr uintptr_t nt_create_keyed_event = 0xb1; // #177
        inline constexpr uintptr_t nt_create_low_box_token = 0xb2; // #178
        inline constexpr uintptr_t nt_create_mailslot_file = 0xb3; // #179
        inline constexpr uintptr_t nt_create_mutant = 0xb4; // #180
        inline constexpr uintptr_t nt_create_named_pipe_file = 0xb5; // #181
        inline constexpr uintptr_t nt_create_paging_file = 0xb6; // #182
        inline constexpr uintptr_t nt_create_partition = 0xb7; // #183
        inline constexpr uintptr_t nt_create_port = 0xb8; // #184
        inline constexpr uintptr_t nt_create_private_namespace = 0xb9; // #185
        inline constexpr uintptr_t nt_create_process = 0xba; // #186
        inline constexpr uintptr_t nt_create_profile = 0xbb; // #187
        inline constexpr uintptr_t nt_create_profile_ex = 0xbc; // #188
        inline constexpr uintptr_t nt_create_registry_transaction = 0xbd; // #189
        inline constexpr uintptr_t nt_create_resource_manager = 0xbe; // #190
        inline constexpr uintptr_t nt_create_section_ex = 0xbf; // #191
        inline constexpr uintptr_t nt_create_semaphore = 0xc0; // #192
        inline constexpr uintptr_t nt_create_symbolic_link_object = 0xc1; // #193
        inline constexpr uintptr_t nt_create_thread_ex = 0xc2; // #194
        inline constexpr uintptr_t nt_create_timer = 0xc3; // #195
        inline constexpr uintptr_t nt_create_timer2 = 0xc4; // #196
        inline constexpr uintptr_t nt_create_token = 0xc5; // #197
        inline constexpr uintptr_t nt_create_token_ex = 0xc6; // #198
        inline constexpr uintptr_t nt_create_transaction = 0xc7; // #199
        inline constexpr uintptr_t nt_create_transaction_manager = 0xc8; // #200
        inline constexpr uintptr_t nt_create_user_process = 0xc9; // #201
        inline constexpr uintptr_t nt_create_wait_completion_packet = 0xca; // #202
        inline constexpr uintptr_t nt_create_waitable_port = 0xcb; // #203
        inline constexpr uintptr_t nt_create_wnf_state_name = 0xcc; // #204
        inline constexpr uintptr_t nt_create_worker_factory = 0xcd; // #205
        inline constexpr uintptr_t nt_debug_active_process = 0xce; // #206
        inline constexpr uintptr_t nt_debug_continue = 0xcf; // #207
        inline constexpr uintptr_t nt_delete_atom = 0xd0; // #208
        inline constexpr uintptr_t nt_delete_boot_entry = 0xd1; // #209
        inline constexpr uintptr_t nt_delete_driver_entry = 0xd2; // #210
        inline constexpr uintptr_t nt_delete_file = 0xd3; // #211
        inline constexpr uintptr_t nt_delete_key = 0xd4; // #212
        inline constexpr uintptr_t nt_delete_object_audit_alarm = 0xd5; // #213
        inline constexpr uintptr_t nt_delete_private_namespace = 0xd6; // #214
        inline constexpr uintptr_t nt_delete_value_key = 0xd7; // #215
        inline constexpr uintptr_t nt_delete_wnf_state_data = 0xd8; // #216
        inline constexpr uintptr_t nt_delete_wnf_state_name = 0xd9; // #217
        inline constexpr uintptr_t nt_direct_graphics_call = 0xda; // #218
        inline constexpr uintptr_t nt_disable_last_known_good = 0xdb; // #219
        inline constexpr uintptr_t nt_display_string = 0xdc; // #220
        inline constexpr uintptr_t nt_draw_text = 0xdd; // #221
        inline constexpr uintptr_t nt_enable_last_known_good = 0xde; // #222
        inline constexpr uintptr_t nt_enumerate_boot_entries = 0xdf; // #223
        inline constexpr uintptr_t nt_enumerate_driver_entries = 0xe0; // #224
        inline constexpr uintptr_t nt_enumerate_system_environment_values_ex = 0xe1; // #225
        inline constexpr uintptr_t nt_enumerate_transaction_object = 0xe2; // #226
        inline constexpr uintptr_t nt_extend_section = 0xe3; // #227
        inline constexpr uintptr_t nt_filter_boot_option = 0xe4; // #228
        inline constexpr uintptr_t nt_filter_token = 0xe5; // #229
        inline constexpr uintptr_t nt_filter_token_ex = 0xe6; // #230
        inline constexpr uintptr_t nt_flush_buffers_file_ex = 0xe7; // #231
        inline constexpr uintptr_t nt_flush_install_u_i_language = 0xe8; // #232
        inline constexpr uintptr_t nt_flush_instruction_cache = 0xe9; // #233
        inline constexpr uintptr_t nt_flush_key = 0xea; // #234
        inline constexpr uintptr_t nt_flush_process_write_buffers = 0xeb; // #235
        inline constexpr uintptr_t nt_flush_virtual_memory = 0xec; // #236
        inline constexpr uintptr_t nt_flush_write_buffer = 0xed; // #237
        inline constexpr uintptr_t nt_free_user_physical_pages = 0xee; // #238
        inline constexpr uintptr_t nt_freeze_registry = 0xef; // #239
        inline constexpr uintptr_t nt_freeze_transactions = 0xf0; // #240
        inline constexpr uintptr_t nt_get_cached_signing_level = 0xf1; // #241
        inline constexpr uintptr_t nt_get_complete_wnf_state_subscription = 0xf2; // #242
        inline constexpr uintptr_t nt_get_context_thread = 0xf3; // #243
        inline constexpr uintptr_t nt_get_current_processor_number = 0xf4; // #244
        inline constexpr uintptr_t nt_get_current_processor_number_ex = 0xf5; // #245
        inline constexpr uintptr_t nt_get_device_power_state = 0xf6; // #246
        inline constexpr uintptr_t nt_get_m_u_i_registry_info = 0xf7; // #247
        inline constexpr uintptr_t nt_get_next_process = 0xf8; // #248
        inline constexpr uintptr_t nt_get_next_thread = 0xf9; // #249
        inline constexpr uintptr_t nt_get_nls_section_ptr = 0xfa; // #250
        inline constexpr uintptr_t nt_get_notification_resource_manager = 0xfb; // #251
        inline constexpr uintptr_t nt_get_write_watch = 0xfc; // #252
        inline constexpr uintptr_t nt_impersonate_anonymous_token = 0xfd; // #253
        inline constexpr uintptr_t nt_impersonate_thread = 0xfe; // #254
        inline constexpr uintptr_t nt_initialize_enclave = 0xff; // #255
        inline constexpr uintptr_t nt_initialize_nls_files = 0x100; // #256
        inline constexpr uintptr_t nt_initialize_registry = 0x101; // #257
        inline constexpr uintptr_t nt_initiate_power_action = 0x102; // #258
        inline constexpr uintptr_t nt_is_system_resume_automatic = 0x103; // #259
        inline constexpr uintptr_t nt_is_u_i_language_comitted = 0x104; // #260
        inline constexpr uintptr_t nt_listen_port = 0x105; // #261
        inline constexpr uintptr_t nt_load_driver = 0x106; // #262
        inline constexpr uintptr_t nt_load_enclave_data = 0x107; // #263
        inline constexpr uintptr_t nt_load_key = 0x108; // #264
        inline constexpr uintptr_t nt_load_key2 = 0x109; // #265
        inline constexpr uintptr_t nt_load_key_ex = 0x10a; // #266
        inline constexpr uintptr_t nt_lock_file = 0x10b; // #267
        inline constexpr uintptr_t nt_lock_product_activation_keys = 0x10c; // #268
        inline constexpr uintptr_t nt_lock_registry_key = 0x10d; // #269
        inline constexpr uintptr_t nt_lock_virtual_memory = 0x10e; // #270
        inline constexpr uintptr_t nt_make_permanent_object = 0x10f; // #271
        inline constexpr uintptr_t nt_make_temporary_object = 0x110; // #272
        inline constexpr uintptr_t nt_manage_hot_patch = 0x111; // #273
        inline constexpr uintptr_t nt_manage_partition = 0x112; // #274
        inline constexpr uintptr_t nt_map_c_m_f_module = 0x113; // #275
        inline constexpr uintptr_t nt_map_user_physical_pages = 0x114; // #276
        inline constexpr uintptr_t nt_map_view_of_section_ex = 0x115; // #277
        inline constexpr uintptr_t nt_modify_boot_entry = 0x116; // #278
        inline constexpr uintptr_t nt_modify_driver_entry = 0x117; // #279
        inline constexpr uintptr_t nt_notify_change_directory_file = 0x118; // #280
        inline constexpr uintptr_t nt_notify_change_directory_file_ex = 0x119; // #281
        inline constexpr uintptr_t nt_notify_change_key = 0x11a; // #282
        inline constexpr uintptr_t nt_notify_change_multiple_keys = 0x11b; // #283
        inline constexpr uintptr_t nt_notify_change_session = 0x11c; // #284
        inline constexpr uintptr_t nt_open_enlistment = 0x11d; // #285
        inline constexpr uintptr_t nt_open_event_pair = 0x11e; // #286
        inline constexpr uintptr_t nt_open_io_completion = 0x11f; // #287
        inline constexpr uintptr_t nt_open_job_object = 0x120; // #288
        inline constexpr uintptr_t nt_open_key_ex = 0x121; // #289
        inline constexpr uintptr_t nt_open_key_transacted = 0x122; // #290
        inline constexpr uintptr_t nt_open_key_transacted_ex = 0x123; // #291
        inline constexpr uintptr_t nt_open_keyed_event = 0x124; // #292
        inline constexpr uintptr_t nt_open_mutant = 0x125; // #293
        inline constexpr uintptr_t nt_open_object_audit_alarm = 0x126; // #294
        inline constexpr uintptr_t nt_open_partition = 0x127; // #295
        inline constexpr uintptr_t nt_open_private_namespace = 0x128; // #296
        inline constexpr uintptr_t nt_open_process_token = 0x129; // #297
        inline constexpr uintptr_t nt_open_registry_transaction = 0x12a; // #298
        inline constexpr uintptr_t nt_open_resource_manager = 0x12b; // #299
        inline constexpr uintptr_t nt_open_semaphore = 0x12c; // #300
        inline constexpr uintptr_t nt_open_session = 0x12d; // #301
        inline constexpr uintptr_t nt_open_symbolic_link_object = 0x12e; // #302
        inline constexpr uintptr_t nt_open_thread = 0x12f; // #303
        inline constexpr uintptr_t nt_open_timer = 0x130; // #304
        inline constexpr uintptr_t nt_open_transaction = 0x131; // #305
        inline constexpr uintptr_t nt_open_transaction_manager = 0x132; // #306
        inline constexpr uintptr_t nt_plug_play_control = 0x133; // #307
        inline constexpr uintptr_t nt_pre_prepare_complete = 0x134; // #308
        inline constexpr uintptr_t nt_pre_prepare_enlistment = 0x135; // #309
        inline constexpr uintptr_t nt_prepare_complete = 0x136; // #310
        inline constexpr uintptr_t nt_prepare_enlistment = 0x137; // #311
        inline constexpr uintptr_t nt_privilege_check = 0x138; // #312
        inline constexpr uintptr_t nt_privilege_object_audit_alarm = 0x139; // #313
        inline constexpr uintptr_t nt_privileged_service_audit_alarm = 0x13a; // #314
        inline constexpr uintptr_t nt_propagation_complete = 0x13b; // #315
        inline constexpr uintptr_t nt_propagation_failed = 0x13c; // #316
        inline constexpr uintptr_t nt_pss_capture_va_space_bulk = 0x13d; // #317
        inline constexpr uintptr_t nt_pulse_event = 0x13e; // #318
        inline constexpr uintptr_t nt_query_auxiliary_counter_frequency = 0x13f; // #319
        inline constexpr uintptr_t nt_query_boot_entry_order = 0x140; // #320
        inline constexpr uintptr_t nt_query_boot_options = 0x141; // #321
        inline constexpr uintptr_t nt_query_debug_filter_state = 0x142; // #322
        inline constexpr uintptr_t nt_query_directory_file_ex = 0x143; // #323
        inline constexpr uintptr_t nt_query_directory_object = 0x144; // #324
        inline constexpr uintptr_t nt_query_driver_entry_order = 0x145; // #325
        inline constexpr uintptr_t nt_query_ea_file = 0x146; // #326
        inline constexpr uintptr_t nt_query_full_attributes_file = 0x147; // #327
        inline constexpr uintptr_t nt_query_information_atom = 0x148; // #328
        inline constexpr uintptr_t nt_query_information_by_name = 0x149; // #329
        inline constexpr uintptr_t nt_query_information_enlistment = 0x14a; // #330
        inline constexpr uintptr_t nt_query_information_job_object = 0x14b; // #331
        inline constexpr uintptr_t nt_query_information_port = 0x14c; // #332
        inline constexpr uintptr_t nt_query_information_resource_manager = 0x14d; // #333
        inline constexpr uintptr_t nt_query_information_transaction = 0x14e; // #334
        inline constexpr uintptr_t nt_query_information_transaction_manager = 0x14f; // #335
        inline constexpr uintptr_t nt_query_information_worker_factory = 0x150; // #336
        inline constexpr uintptr_t nt_query_install_u_i_language = 0x151; // #337
        inline constexpr uintptr_t nt_query_interval_profile = 0x152; // #338
        inline constexpr uintptr_t nt_query_io_completion = 0x153; // #339
        inline constexpr uintptr_t nt_query_license_value = 0x154; // #340
        inline constexpr uintptr_t nt_query_multiple_value_key = 0x155; // #341
        inline constexpr uintptr_t nt_query_mutant = 0x156; // #342
        inline constexpr uintptr_t nt_query_open_sub_keys = 0x157; // #343
        inline constexpr uintptr_t nt_query_open_sub_keys_ex = 0x158; // #344
        inline constexpr uintptr_t nt_query_port_information_process = 0x159; // #345
        inline constexpr uintptr_t nt_query_quota_information_file = 0x15a; // #346
        inline constexpr uintptr_t nt_query_security_attributes_token = 0x15b; // #347
        inline constexpr uintptr_t nt_query_security_object = 0x15c; // #348
        inline constexpr uintptr_t nt_query_security_policy = 0x15d; // #349
        inline constexpr uintptr_t nt_query_semaphore = 0x15e; // #350
        inline constexpr uintptr_t nt_query_symbolic_link_object = 0x15f; // #351
        inline constexpr uintptr_t nt_query_system_environment_value = 0x160; // #352
        inline constexpr uintptr_t nt_query_system_environment_value_ex = 0x161; // #353
        inline constexpr uintptr_t nt_query_system_information_ex = 0x162; // #354
        inline constexpr uintptr_t nt_query_timer_resolution = 0x163; // #355
        inline constexpr uintptr_t nt_query_wnf_state_data = 0x164; // #356
        inline constexpr uintptr_t nt_query_wnf_state_name_information = 0x165; // #357
        inline constexpr uintptr_t nt_queue_apc_thread_ex = 0x166; // #358
        inline constexpr uintptr_t nt_queue_apc_thread_ex2 = 0x167; // #359
        inline constexpr uintptr_t nt_raise_exception = 0x168; // #360
        inline constexpr uintptr_t nt_raise_hard_error = 0x169; // #361
        inline constexpr uintptr_t nt_read_only_enlistment = 0x16a; // #362
        inline constexpr uintptr_t nt_recover_enlistment = 0x16b; // #363
        inline constexpr uintptr_t nt_recover_resource_manager = 0x16c; // #364
        inline constexpr uintptr_t nt_recover_transaction_manager = 0x16d; // #365
        inline constexpr uintptr_t nt_register_protocol_address_information = 0x16e; // #366
        inline constexpr uintptr_t nt_register_thread_terminate_port = 0x16f; // #367
        inline constexpr uintptr_t nt_release_keyed_event = 0x170; // #368
        inline constexpr uintptr_t nt_release_worker_factory_worker = 0x171; // #369
        inline constexpr uintptr_t nt_remove_io_completion_ex = 0x172; // #370
        inline constexpr uintptr_t nt_remove_process_debug = 0x173; // #371
        inline constexpr uintptr_t nt_rename_key = 0x174; // #372
        inline constexpr uintptr_t nt_rename_transaction_manager = 0x175; // #373
        inline constexpr uintptr_t nt_replace_key = 0x176; // #374
        inline constexpr uintptr_t nt_replace_partition_unit = 0x177; // #375
        inline constexpr uintptr_t nt_reply_wait_reply_port = 0x178; // #376
        inline constexpr uintptr_t nt_request_port = 0x179; // #377
        inline constexpr uintptr_t nt_reset_event = 0x17a; // #378
        inline constexpr uintptr_t nt_reset_write_watch = 0x17b; // #379
        inline constexpr uintptr_t nt_restore_key = 0x17c; // #380
        inline constexpr uintptr_t nt_resume_process = 0x17d; // #381
        inline constexpr uintptr_t nt_revert_container_impersonation = 0x17e; // #382
        inline constexpr uintptr_t nt_rollback_complete = 0x17f; // #383
        inline constexpr uintptr_t nt_rollback_enlistment = 0x180; // #384
        inline constexpr uintptr_t nt_rollback_registry_transaction = 0x181; // #385
        inline constexpr uintptr_t nt_rollback_transaction = 0x182; // #386
        inline constexpr uintptr_t nt_rollforward_transaction_manager = 0x183; // #387
        inline constexpr uintptr_t nt_save_key = 0x184; // #388
        inline constexpr uintptr_t nt_save_key_ex = 0x185; // #389
        inline constexpr uintptr_t nt_save_merged_keys = 0x186; // #390
        inline constexpr uintptr_t nt_secure_connect_port = 0x187; // #391
        inline constexpr uintptr_t nt_serialize_boot = 0x188; // #392
        inline constexpr uintptr_t nt_set_boot_entry_order = 0x189; // #393
        inline constexpr uintptr_t nt_set_boot_options = 0x18a; // #394
        inline constexpr uintptr_t nt_set_cached_signing_level = 0x18b; // #395
        inline constexpr uintptr_t nt_set_cached_signing_level2 = 0x18c; // #396
        inline constexpr uintptr_t nt_set_context_thread = 0x18d; // #397
        inline constexpr uintptr_t nt_set_debug_filter_state = 0x18e; // #398
        inline constexpr uintptr_t nt_set_default_hard_error_port = 0x18f; // #399
        inline constexpr uintptr_t nt_set_default_locale = 0x190; // #400
        inline constexpr uintptr_t nt_set_default_u_i_language = 0x191; // #401
        inline constexpr uintptr_t nt_set_driver_entry_order = 0x192; // #402
        inline constexpr uintptr_t nt_set_ea_file = 0x193; // #403
        inline constexpr uintptr_t nt_set_high_event_pair = 0x194; // #404
        inline constexpr uintptr_t nt_set_high_wait_low_event_pair = 0x195; // #405
        inline constexpr uintptr_t nt_set_i_r_timer = 0x196; // #406
        inline constexpr uintptr_t nt_set_information_debug_object = 0x197; // #407
        inline constexpr uintptr_t nt_set_information_enlistment = 0x198; // #408
        inline constexpr uintptr_t nt_set_information_job_object = 0x199; // #409
        inline constexpr uintptr_t nt_set_information_key = 0x19a; // #410
        inline constexpr uintptr_t nt_set_information_resource_manager = 0x19b; // #411
        inline constexpr uintptr_t nt_set_information_symbolic_link = 0x19c; // #412
        inline constexpr uintptr_t nt_set_information_token = 0x19d; // #413
        inline constexpr uintptr_t nt_set_information_transaction = 0x19e; // #414
        inline constexpr uintptr_t nt_set_information_transaction_manager = 0x19f; // #415
        inline constexpr uintptr_t nt_set_information_virtual_memory = 0x1a0; // #416
        inline constexpr uintptr_t nt_set_information_worker_factory = 0x1a1; // #417
        inline constexpr uintptr_t nt_set_interval_profile = 0x1a2; // #418
        inline constexpr uintptr_t nt_set_io_completion = 0x1a3; // #419
        inline constexpr uintptr_t nt_set_io_completion_ex = 0x1a4; // #420
        inline constexpr uintptr_t nt_set_ldt_entries = 0x1a5; // #421
        inline constexpr uintptr_t nt_set_low_event_pair = 0x1a6; // #422
        inline constexpr uintptr_t nt_set_low_wait_high_event_pair = 0x1a7; // #423
        inline constexpr uintptr_t nt_set_quota_information_file = 0x1a8; // #424
        inline constexpr uintptr_t nt_set_security_object = 0x1a9; // #425
        inline constexpr uintptr_t nt_set_system_environment_value = 0x1aa; // #426
        inline constexpr uintptr_t nt_set_system_environment_value_ex = 0x1ab; // #427
        inline constexpr uintptr_t nt_set_system_information = 0x1ac; // #428
        inline constexpr uintptr_t nt_set_system_power_state = 0x1ad; // #429
        inline constexpr uintptr_t nt_set_system_time = 0x1ae; // #430
        inline constexpr uintptr_t nt_set_thread_execution_state = 0x1af; // #431
        inline constexpr uintptr_t nt_set_timer2 = 0x1b0; // #432
        inline constexpr uintptr_t nt_set_timer_ex = 0x1b1; // #433
        inline constexpr uintptr_t nt_set_timer_resolution = 0x1b2; // #434
        inline constexpr uintptr_t nt_set_uuid_seed = 0x1b3; // #435
        inline constexpr uintptr_t nt_set_volume_information_file = 0x1b4; // #436
        inline constexpr uintptr_t nt_set_wnf_process_notification_event = 0x1b5; // #437
        inline constexpr uintptr_t nt_shutdown_system = 0x1b6; // #438
        inline constexpr uintptr_t nt_shutdown_worker_factory = 0x1b7; // #439
        inline constexpr uintptr_t nt_signal_and_wait_for_single_object = 0x1b8; // #440
        inline constexpr uintptr_t nt_single_phase_reject = 0x1b9; // #441
        inline constexpr uintptr_t nt_start_profile = 0x1ba; // #442
        inline constexpr uintptr_t nt_stop_profile = 0x1bb; // #443
        inline constexpr uintptr_t nt_subscribe_wnf_state_change = 0x1bc; // #444
        inline constexpr uintptr_t nt_suspend_process = 0x1bd; // #445
        inline constexpr uintptr_t nt_suspend_thread = 0x1be; // #446
        inline constexpr uintptr_t nt_system_debug_control = 0x1bf; // #447
        inline constexpr uintptr_t nt_terminate_enclave = 0x1c0; // #448
        inline constexpr uintptr_t nt_terminate_job_object = 0x1c1; // #449
        inline constexpr uintptr_t nt_test_alert = 0x1c2; // #450
        inline constexpr uintptr_t nt_thaw_registry = 0x1c3; // #451
        inline constexpr uintptr_t nt_thaw_transactions = 0x1c4; // #452
        inline constexpr uintptr_t nt_trace_control = 0x1c5; // #453
        inline constexpr uintptr_t nt_translate_file_path = 0x1c6; // #454
        inline constexpr uintptr_t nt_ums_thread_yield = 0x1c7; // #455
        inline constexpr uintptr_t nt_unload_driver = 0x1c8; // #456
        inline constexpr uintptr_t nt_unload_key = 0x1c9; // #457
        inline constexpr uintptr_t nt_unload_key2 = 0x1ca; // #458
        inline constexpr uintptr_t nt_unload_key_ex = 0x1cb; // #459
        inline constexpr uintptr_t nt_unlock_file = 0x1cc; // #460
        inline constexpr uintptr_t nt_unlock_virtual_memory = 0x1cd; // #461
        inline constexpr uintptr_t nt_unmap_view_of_section_ex = 0x1ce; // #462
        inline constexpr uintptr_t nt_unsubscribe_wnf_state_change = 0x1cf; // #463
        inline constexpr uintptr_t nt_update_wnf_state_data = 0x1d0; // #464
        inline constexpr uintptr_t nt_vdm_control = 0x1d1; // #465
        inline constexpr uintptr_t nt_wait_for_alert_by_thread_id = 0x1d2; // #466
        inline constexpr uintptr_t nt_wait_for_debug_event = 0x1d3; // #467
        inline constexpr uintptr_t nt_wait_for_keyed_event = 0x1d4; // #468
        inline constexpr uintptr_t nt_wait_for_work_via_worker_factory = 0x1d5; // #469
        inline constexpr uintptr_t nt_wait_high_event_pair = 0x1d6; // #470
        inline constexpr uintptr_t nt_load_key3 = 0x1d7; // #471
        inline constexpr uintptr_t nt_wait_low_event_pair = 0x1d8; // #472
    }

    inline constexpr const char* map[] = {
      "NtAccessCheck", // 0x0
      "NtWorkerFactoryWorkerReady", // 0x1
      "NtAcceptConnectPort", // 0x2
      "NtMapUserPhysicalPagesScatter", // 0x3
      "NtWaitForSingleObject", // 0x4
      "NtCallbackReturn", // 0x5
      "NtReadFile", // 0x6
      "NtDeviceIoControlFile", // 0x7
      "NtWriteFile", // 0x8
      "NtRemoveIoCompletion", // 0x9
      "NtReleaseSemaphore", // 0xa
      "NtReplyWaitReceivePort", // 0xb
      "NtReplyPort", // 0xc
      "NtSetInformationThread", // 0xd
      "NtSetEvent", // 0xe
      "NtClose", // 0xf
      "NtQueryObject", // 0x10
      "NtQueryInformationFile", // 0x11
      "NtOpenKey", // 0x12
      "NtEnumerateValueKey", // 0x13
      "NtFindAtom", // 0x14
      "NtQueryDefaultLocale", // 0x15
      "NtQueryKey", // 0x16
      "NtQueryValueKey", // 0x17
      "NtAllocateVirtualMemory", // 0x18
      "NtQueryInformationProcess", // 0x19
      "NtWaitForMultipleObjects32", // 0x1a
      "NtWriteFileGather", // 0x1b
      "NtSetInformationProcess", // 0x1c
      "NtCreateKey", // 0x1d
      "NtFreeVirtualMemory", // 0x1e
      "NtImpersonateClientOfPort", // 0x1f
      "NtReleaseMutant", // 0x20
      "NtQueryInformationToken", // 0x21
      "NtRequestWaitReplyPort", // 0x22
      "NtQueryVirtualMemory", // 0x23
      "NtOpenThreadToken", // 0x24
      "NtQueryInformationThread", // 0x25
      "NtOpenProcess", // 0x26
      "NtSetInformationFile", // 0x27
      "NtMapViewOfSection", // 0x28
      "NtAccessCheckAndAuditAlarm", // 0x29
      "NtUnmapViewOfSection", // 0x2a
      "NtReplyWaitReceivePortEx", // 0x2b
      "NtTerminateProcess", // 0x2c
      "NtSetEventBoostPriority", // 0x2d
      "NtReadFileScatter", // 0x2e
      "NtOpenThreadTokenEx", // 0x2f
      "NtOpenProcessTokenEx", // 0x30
      "NtQueryPerformanceCounter", // 0x31
      "NtEnumerateKey", // 0x32
      "NtOpenFile", // 0x33
      "NtDelayExecution", // 0x34
      "NtQueryDirectoryFile", // 0x35
      "NtQuerySystemInformation", // 0x36
      "NtOpenSection", // 0x37
      "NtQueryTimer", // 0x38
      "NtFsControlFile", // 0x39
      "NtWriteVirtualMemory", // 0x3a
      "NtCloseObjectAuditAlarm", // 0x3b
      "NtDuplicateObject", // 0x3c
      "NtQueryAttributesFile", // 0x3d
      "NtClearEvent", // 0x3e
      "NtReadVirtualMemory", // 0x3f
      "NtOpenEvent", // 0x40
      "NtAdjustPrivilegesToken", // 0x41
      "NtDuplicateToken", // 0x42
      "NtContinue", // 0x43
      "NtQueryDefaultUILanguage", // 0x44
      "NtQueueApcThread", // 0x45
      "NtYieldExecution", // 0x46
      "NtAddAtom", // 0x47
      "NtCreateEvent", // 0x48
      "NtQueryVolumeInformationFile", // 0x49
      "NtCreateSection", // 0x4a
      "NtFlushBuffersFile", // 0x4b
      "NtApphelpCacheControl", // 0x4c
      "NtCreateProcessEx", // 0x4d
      "NtCreateThread", // 0x4e
      "NtIsProcessInJob", // 0x4f
      "NtProtectVirtualMemory", // 0x50
      "NtQuerySection", // 0x51
      "NtResumeThread", // 0x52
      "NtTerminateThread", // 0x53
      "NtReadRequestData", // 0x54
      "NtCreateFile", // 0x55
      "NtQueryEvent", // 0x56
      "NtWriteRequestData", // 0x57
      "NtOpenDirectoryObject", // 0x58
      "NtAccessCheckByTypeAndAuditAlarm", // 0x59
      nullptr, // 0x5a
      "NtWaitForMultipleObjects", // 0x5b
      "NtSetInformationObject", // 0x5c
      "NtCancelIoFile", // 0x5d
      "NtTraceEvent", // 0x5e
      "NtPowerInformation", // 0x5f
      "NtSetValueKey", // 0x60
      "NtCancelTimer", // 0x61
      "NtSetTimer", // 0x62
      "NtAccessCheckByType", // 0x63
      "NtAccessCheckByTypeResultList", // 0x64
      "NtAccessCheckByTypeResultListAndAuditAlarm", // 0x65
      "NtAccessCheckByTypeResultListAndAuditAlarmByHandle", // 0x66
      "NtAcquireCrossVmMutant", // 0x67
      "NtAcquireProcessActivityReference", // 0x68
      "NtAddAtomEx", // 0x69
      "NtAddBootEntry", // 0x6a
      "NtAddDriverEntry", // 0x6b
      "NtAdjustGroupsToken", // 0x6c
      "NtAdjustTokenClaimsAndDeviceGroups", // 0x6d
      "NtAlertResumeThread", // 0x6e
      "NtAlertThread", // 0x6f
      "NtAlertThreadByThreadId", // 0x70
      "NtAllocateLocallyUniqueId", // 0x71
      "NtAllocateReserveObject", // 0x72
      "NtAllocateUserPhysicalPages", // 0x73
      "NtAllocateUserPhysicalPagesEx", // 0x74
      "NtAllocateUuids", // 0x75
      "NtAllocateVirtualMemoryEx", // 0x76
      "NtAlpcAcceptConnectPort", // 0x77
      "NtAlpcCancelMessage", // 0x78
      "NtAlpcConnectPort", // 0x79
      "NtAlpcConnectPortEx", // 0x7a
      "NtAlpcCreatePort", // 0x7b
      "NtAlpcCreatePortSection", // 0x7c
      "NtAlpcCreateResourceReserve", // 0x7d
      "NtAlpcCreateSectionView", // 0x7e
      "NtAlpcCreateSecurityContext", // 0x7f
      "NtAlpcDeletePortSection", // 0x80
      "NtAlpcDeleteResourceReserve", // 0x81
      "NtAlpcDeleteSectionView", // 0x82
      "NtAlpcDeleteSecurityContext", // 0x83
      "NtAlpcDisconnectPort", // 0x84
      "NtAlpcImpersonateClientContainerOfPort", // 0x85
      "NtAlpcImpersonateClientOfPort", // 0x86
      "NtAlpcOpenSenderProcess", // 0x87
      "NtAlpcOpenSenderThread", // 0x88
      "NtAlpcQueryInformation", // 0x89
      "NtAlpcQueryInformationMessage", // 0x8a
      "NtAlpcRevokeSecurityContext", // 0x8b
      "NtAlpcSendWaitReceivePort", // 0x8c
      "NtAlpcSetInformation", // 0x8d
      "NtAreMappedFilesTheSame", // 0x8e
      "NtAssignProcessToJobObject", // 0x8f
      "NtAssociateWaitCompletionPacket", // 0x90
      "NtCallEnclave", // 0x91
      "NtCancelIoFileEx", // 0x92
      "NtCancelSynchronousIoFile", // 0x93
      "NtCancelTimer2", // 0x94
      "NtCancelWaitCompletionPacket", // 0x95
      "NtCommitComplete", // 0x96
      "NtCommitEnlistment", // 0x97
      "NtCommitRegistryTransaction", // 0x98
      "NtCommitTransaction", // 0x99
      "NtCompactKeys", // 0x9a
      "NtCompareObjects", // 0x9b
      "NtCompareSigningLevels", // 0x9c
      "NtCompareTokens", // 0x9d
      "NtCompleteConnectPort", // 0x9e
      "NtCompressKey", // 0x9f
      "NtConnectPort", // 0xa0
      "NtContinueEx", // 0xa1
      "NtConvertBetweenAuxiliaryCounterAndPerformanceCounter", // 0xa2
      "NtCopyFileChunk", // 0xa3
      "NtCreateCrossVmEvent", // 0xa4
      "NtCreateCrossVmMutant", // 0xa5
      "NtCreateDebugObject", // 0xa6
      "NtCreateDirectoryObject", // 0xa7
      "NtCreateDirectoryObjectEx", // 0xa8
      "NtCreateEnclave", // 0xa9
      "NtCreateEnlistment", // 0xaa
      "NtCreateEventPair", // 0xab
      "NtCreateIRTimer", // 0xac
      "NtCreateIoCompletion", // 0xad
      "NtCreateJobObject", // 0xae
      "NtCreateJobSet", // 0xaf
      "NtCreateKeyTransacted", // 0xb0
      "NtCreateKeyedEvent", // 0xb1
      "NtCreateLowBoxToken", // 0xb2
      "NtCreateMailslotFile", // 0xb3
      "NtCreateMutant", // 0xb4
      "NtCreateNamedPipeFile", // 0xb5
      "NtCreatePagingFile", // 0xb6
      "NtCreatePartition", // 0xb7
      "NtCreatePort", // 0xb8
      "NtCreatePrivateNamespace", // 0xb9
      "NtCreateProcess", // 0xba
      "NtCreateProfile", // 0xbb
      "NtCreateProfileEx", // 0xbc
      "NtCreateRegistryTransaction", // 0xbd
      "NtCreateResourceManager", // 0xbe
      "NtCreateSectionEx", // 0xbf
      "NtCreateSemaphore", // 0xc0
      "NtCreateSymbolicLinkObject", // 0xc1
      "NtCreateThreadEx", // 0xc2
      "NtCreateTimer", // 0xc3
      "NtCreateTimer2", // 0xc4
      "NtCreateToken", // 0xc5
      "NtCreateTokenEx", // 0xc6
      "NtCreateTransaction", // 0xc7
      "NtCreateTransactionManager", // 0xc8
      "NtCreateUserProcess", // 0xc9
      "NtCreateWaitCompletionPacket", // 0xca
      "NtCreateWaitablePort", // 0xcb
      "NtCreateWnfStateName", // 0xcc
      "NtCreateWorkerFactory", // 0xcd
      "NtDebugActiveProcess", // 0xce
      "NtDebugContinue", // 0xcf
      "NtDeleteAtom", // 0xd0
      "NtDeleteBootEntry", // 0xd1
      "NtDeleteDriverEntry", // 0xd2
      "NtDeleteFile", // 0xd3
      "NtDeleteKey", // 0xd4
      "NtDeleteObjectAuditAlarm", // 0xd5
      "NtDeletePrivateNamespace", // 0xd6
      "NtDeleteValueKey", // 0xd7
      "NtDeleteWnfStateData", // 0xd8
      "NtDeleteWnfStateName", // 0xd9
      "NtDirectGraphicsCall", // 0xda
      "NtDisableLastKnownGood", // 0xdb
      "NtDisplayString", // 0xdc
      "NtDrawText", // 0xdd
      "NtEnableLastKnownGood", // 0xde
      "NtEnumerateBootEntries", // 0xdf
      "NtEnumerateDriverEntries", // 0xe0
      "NtEnumerateSystemEnvironmentValuesEx", // 0xe1
      "NtEnumerateTransactionObject", // 0xe2
      "NtExtendSection", // 0xe3
      "NtFilterBootOption", // 0xe4
      "NtFilterToken", // 0xe5
      "NtFilterTokenEx", // 0xe6
      "NtFlushBuffersFileEx", // 0xe7
      "NtFlushInstallUILanguage", // 0xe8
      "NtFlushInstructionCache", // 0xe9
      "NtFlushKey", // 0xea
      "NtFlushProcessWriteBuffers", // 0xeb
      "NtFlushVirtualMemory", // 0xec
      "NtFlushWriteBuffer", // 0xed
      "NtFreeUserPhysicalPages", // 0xee
      "NtFreezeRegistry", // 0xef
      "NtFreezeTransactions", // 0xf0
      "NtGetCachedSigningLevel", // 0xf1
      "NtGetCompleteWnfStateSubscription", // 0xf2
      "NtGetContextThread", // 0xf3
      "NtGetCurrentProcessorNumber", // 0xf4
      "NtGetCurrentProcessorNumberEx", // 0xf5
      "NtGetDevicePowerState", // 0xf6
      "NtGetMUIRegistryInfo", // 0xf7
      "NtGetNextProcess", // 0xf8
      "NtGetNextThread", // 0xf9
      "NtGetNlsSectionPtr", // 0xfa
      "NtGetNotificationResourceManager", // 0xfb
      "NtGetWriteWatch", // 0xfc
      "NtImpersonateAnonymousToken", // 0xfd
      "NtImpersonateThread", // 0xfe
      "NtInitializeEnclave", // 0xff
      "NtInitializeNlsFiles", // 0x100
      "NtInitializeRegistry", // 0x101
      "NtInitiatePowerAction", // 0x102
      "NtIsSystemResumeAutomatic", // 0x103
      "NtIsUILanguageComitted", // 0x104
      "NtListenPort", // 0x105
      "NtLoadDriver", // 0x106
      "NtLoadEnclaveData", // 0x107
      "NtLoadKey", // 0x108
      "NtLoadKey2", // 0x109
      "NtLoadKeyEx", // 0x10a
      "NtLockFile", // 0x10b
      "NtLockProductActivationKeys", // 0x10c
      "NtLockRegistryKey", // 0x10d
      "NtLockVirtualMemory", // 0x10e
      "NtMakePermanentObject", // 0x10f
      "NtMakeTemporaryObject", // 0x110
      "NtManageHotPatch", // 0x111
      "NtManagePartition", // 0x112
      "NtMapCMFModule", // 0x113
      "NtMapUserPhysicalPages", // 0x114
      "NtMapViewOfSectionEx", // 0x115
      "NtModifyBootEntry", // 0x116
      "NtModifyDriverEntry", // 0x117
      "NtNotifyChangeDirectoryFile", // 0x118
      "NtNotifyChangeDirectoryFileEx", // 0x119
      "NtNotifyChangeKey", // 0x11a
      "NtNotifyChangeMultipleKeys", // 0x11b
      "NtNotifyChangeSession", // 0x11c
      "NtOpenEnlistment", // 0x11d
      "NtOpenEventPair", // 0x11e
      "NtOpenIoCompletion", // 0x11f
      "NtOpenJobObject", // 0x120
      "NtOpenKeyEx", // 0x121
      "NtOpenKeyTransacted", // 0x122
      "NtOpenKeyTransactedEx", // 0x123
      "NtOpenKeyedEvent", // 0x124
      "NtOpenMutant", // 0x125
      "NtOpenObjectAuditAlarm", // 0x126
      "NtOpenPartition", // 0x127
      "NtOpenPrivateNamespace", // 0x128
      "NtOpenProcessToken", // 0x129
      "NtOpenRegistryTransaction", // 0x12a
      "NtOpenResourceManager", // 0x12b
      "NtOpenSemaphore", // 0x12c
      "NtOpenSession", // 0x12d
      "NtOpenSymbolicLinkObject", // 0x12e
      "NtOpenThread", // 0x12f
      "NtOpenTimer", // 0x130
      "NtOpenTransaction", // 0x131
      "NtOpenTransactionManager", // 0x132
      "NtPlugPlayControl", // 0x133
      "NtPrePrepareComplete", // 0x134
      "NtPrePrepareEnlistment", // 0x135
      "NtPrepareComplete", // 0x136
      "NtPrepareEnlistment", // 0x137
      "NtPrivilegeCheck", // 0x138
      "NtPrivilegeObjectAuditAlarm", // 0x139
      "NtPrivilegedServiceAuditAlarm", // 0x13a
      "NtPropagationComplete", // 0x13b
      "NtPropagationFailed", // 0x13c
      "NtPssCaptureVaSpaceBulk", // 0x13d
      "NtPulseEvent", // 0x13e
      "NtQueryAuxiliaryCounterFrequency", // 0x13f
      "NtQueryBootEntryOrder", // 0x140
      "NtQueryBootOptions", // 0x141
      "NtQueryDebugFilterState", // 0x142
      "NtQueryDirectoryFileEx", // 0x143
      "NtQueryDirectoryObject", // 0x144
      "NtQueryDriverEntryOrder", // 0x145
      "NtQueryEaFile", // 0x146
      "NtQueryFullAttributesFile", // 0x147
      "NtQueryInformationAtom", // 0x148
      "NtQueryInformationByName", // 0x149
      "NtQueryInformationEnlistment", // 0x14a
      "NtQueryInformationJobObject", // 0x14b
      "NtQueryInformationPort", // 0x14c
      "NtQueryInformationResourceManager", // 0x14d
      "NtQueryInformationTransaction", // 0x14e
      "NtQueryInformationTransactionManager", // 0x14f
      "NtQueryInformationWorkerFactory", // 0x150
      "NtQueryInstallUILanguage", // 0x151
      "NtQueryIntervalProfile", // 0x152
      "NtQueryIoCompletion", // 0x153
      "NtQueryLicenseValue", // 0x154
      "NtQueryMultipleValueKey", // 0x155
      "NtQueryMutant", // 0x156
      "NtQueryOpenSubKeys", // 0x157
      "NtQueryOpenSubKeysEx", // 0x158
      "NtQueryPortInformationProcess", // 0x159
      "NtQueryQuotaInformationFile", // 0x15a
      "NtQuerySecurityAttributesToken", // 0x15b
      "NtQuerySecurityObject", // 0x15c
      "NtQuerySecurityPolicy", // 0x15d
      "NtQuerySemaphore", // 0x15e
      "NtQuerySymbolicLinkObject", // 0x15f
      "NtQuerySystemEnvironmentValue", // 0x160
      "NtQuerySystemEnvironmentValueEx", // 0x161
      "NtQuerySystemInformationEx", // 0x162
      "NtQueryTimerResolution", // 0x163
      "NtQueryWnfStateData", // 0x164
      "NtQueryWnfStateNameInformation", // 0x165
      "NtQueueApcThreadEx", // 0x166
      "NtQueueApcThreadEx2", // 0x167
      "NtRaiseException", // 0x168
      "NtRaiseHardError", // 0x169
      "NtReadOnlyEnlistment", // 0x16a
      "NtRecoverEnlistment", // 0x16b
      "NtRecoverResourceManager", // 0x16c
      "NtRecoverTransactionManager", // 0x16d
      "NtRegisterProtocolAddressInformation", // 0x16e
      "NtRegisterThreadTerminatePort", // 0x16f
      "NtReleaseKeyedEvent", // 0x170
      "NtReleaseWorkerFactoryWorker", // 0x171
      "NtRemoveIoCompletionEx", // 0x172
      "NtRemoveProcessDebug", // 0x173
      "NtRenameKey", // 0x174
      "NtRenameTransactionManager", // 0x175
      "NtReplaceKey", // 0x176
      "NtReplacePartitionUnit", // 0x177
      "NtReplyWaitReplyPort", // 0x178
      "NtRequestPort", // 0x179
      "NtResetEvent", // 0x17a
      "NtResetWriteWatch", // 0x17b
      "NtRestoreKey", // 0x17c
      "NtResumeProcess", // 0x17d
      "NtRevertContainerImpersonation", // 0x17e
      "NtRollbackComplete", // 0x17f
      "NtRollbackEnlistment", // 0x180
      "NtRollbackRegistryTransaction", // 0x181
      "NtRollbackTransaction", // 0x182
      "NtRollforwardTransactionManager", // 0x183
      "NtSaveKey", // 0x184
      "NtSaveKeyEx", // 0x185
      "NtSaveMergedKeys", // 0x186
      "NtSecureConnectPort", // 0x187
      "NtSerializeBoot", // 0x188
      "NtSetBootEntryOrder", // 0x189
      "NtSetBootOptions", // 0x18a
      "NtSetCachedSigningLevel", // 0x18b
      "NtSetCachedSigningLevel2", // 0x18c
      "NtSetContextThread", // 0x18d
      "NtSetDebugFilterState", // 0x18e
      "NtSetDefaultHardErrorPort", // 0x18f
      "NtSetDefaultLocale", // 0x190
      "NtSetDefaultUILanguage", // 0x191
      "NtSetDriverEntryOrder", // 0x192
      "NtSetEaFile", // 0x193
      "NtSetHighEventPair", // 0x194
      "NtSetHighWaitLowEventPair", // 0x195
      "NtSetIRTimer", // 0x196
      "NtSetInformationDebugObject", // 0x197
      "NtSetInformationEnlistment", // 0x198
      "NtSetInformationJobObject", // 0x199
      "NtSetInformationKey", // 0x19a
      "NtSetInformationResourceManager", // 0x19b
      "NtSetInformationSymbolicLink", // 0x19c
      "NtSetInformationToken", // 0x19d
      "NtSetInformationTransaction", // 0x19e
      "NtSetInformationTransactionManager", // 0x19f
      "NtSetInformationVirtualMemory", // 0x1a0
      "NtSetInformationWorkerFactory", // 0x1a1
      "NtSetIntervalProfile", // 0x1a2
      "NtSetIoCompletion", // 0x1a3
      "NtSetIoCompletionEx", // 0x1a4
      "NtSetLdtEntries", // 0x1a5
      "NtSetLowEventPair", // 0x1a6
      "NtSetLowWaitHighEventPair", // 0x1a7
      "NtSetQuotaInformationFile", // 0x1a8
      "NtSetSecurityObject", // 0x1a9
      "NtSetSystemEnvironmentValue", // 0x1aa
      "NtSetSystemEnvironmentValueEx", // 0x1ab
      "NtSetSystemInformation", // 0x1ac
      "NtSetSystemPowerState", // 0x1ad
      "NtSetSystemTime", // 0x1ae
      "NtSetThreadExecutionState", // 0x1af
      "NtSetTimer2", // 0x1b0
      "NtSetTimerEx", // 0x1b1
      "NtSetTimerResolution", // 0x1b2
      "NtSetUuidSeed", // 0x1b3
      "NtSetVolumeInformationFile", // 0x1b4
      "NtSetWnfProcessNotificationEvent", // 0x1b5
      "NtShutdownSystem", // 0x1b6
      "NtShutdownWorkerFactory", // 0x1b7
      "NtSignalAndWaitForSingleObject", // 0x1b8
      "NtSinglePhaseReject", // 0x1b9
      "NtStartProfile", // 0x1ba
      "NtStopProfile", // 0x1bb
      "NtSubscribeWnfStateChange", // 0x1bc
      "NtSuspendProcess", // 0x1bd
      "NtSuspendThread", // 0x1be
      "NtSystemDebugControl", // 0x1bf
      "NtTerminateEnclave", // 0x1c0
      "NtTerminateJobObject", // 0x1c1
      "NtTestAlert", // 0x1c2
      "NtThawRegistry", // 0x1c3
      "NtThawTransactions", // 0x1c4
      "NtTraceControl", // 0x1c5
      "NtTranslateFilePath", // 0x1c6
      "NtUmsThreadYield", // 0x1c7
      "NtUnloadDriver", // 0x1c8
      "NtUnloadKey", // 0x1c9
      "NtUnloadKey2", // 0x1ca
      "NtUnloadKeyEx", // 0x1cb
      "NtUnlockFile", // 0x1cc
      "NtUnlockVirtualMemory", // 0x1cd
      "NtUnmapViewOfSectionEx", // 0x1ce
      "NtUnsubscribeWnfStateChange", // 0x1cf
      "NtUpdateWnfStateData", // 0x1d0
      "NtVdmControl", // 0x1d1
      "NtWaitForAlertByThreadId", // 0x1d2
      "NtWaitForDebugEvent", // 0x1d3
      "NtWaitForKeyedEvent", // 0x1d4
      "NtWaitForWorkViaWorkerFactory", // 0x1d5
      "NtWaitHighEventPair", // 0x1d6
      "NtLoadKey3", // 0x1d7
      "NtWaitLowEventPair", // 0x1d8
    };

    template<uintptr_t Idx>
    inline constexpr const char* get() {
        if constexpr (Idx < sizeof(map) / sizeof(map[0])) {
            return map[Idx];
        }
        else {
            return nullptr;
        }
    }

} // namespace syscalls
