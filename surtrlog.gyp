{
    'variables': {
        'library%': 'static_library',
    },

    'targets': [
        {
            'target_name': 'surtrlog', 
            'type': '<(library)',

            'sources': [
                'src/logger.cc',
                'include/surtrlog/surtrlog.h',
                'include/surtrlog/version.h',
            ],

            'include_dirs': [
                'include',
            ],

            'direct_dependent_settings': {
                'include_dirs': [
                    'include'
                ]
            },

            'cflags+': [ '-Wno-unused-function']
        },
        {
            'target_name': 'surtrlog_tests',
            'type': 'executable',

            'sources': [
                'tests/surtrlog_test.cc',
            ],

            'dependencies': [
                'surtrlog',
                '<(gtest_dir)/gtest.gyp:gtest_main',
            ],
        }
    ]
}