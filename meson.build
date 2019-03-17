project(
  'bitvec',
  version: '0.10.0',
  license: 'MIT',
  meson_version: '>=0.50.0',
)

cargo = find_program('cargo')
sources = [
  'src/bits.rs',
  'src/boxed.rs',
  'src/cursor.rs',
  'src/ffi.rs',
  'src/lib.rs',
  'src/macros.rs',
  'src/pointer.rs',
  'src/slice.rs',
  'src/vec.rs',
  'src/ffi/boxed.rs',
  'src/ffi/slice.rs',
  'src/ffi/vec.rs',
]

features = []
bitvec_std_enabled = not get_option('std').disabled()
bitvec_alloc_enabled = (
  (get_option('alloc').auto() and bitvec_std_enabled)
  or get_option('alloc').enabled()
)

if bitvec_std_enabled
  features += ['std']
endif
if bitvec_alloc_enabled
  features += ['alloc']
endif
if get_option('ffi').enabled()
  features += ['ffi']
endif

bitvec = custom_target(
  'bitvec',
  command: [
    cargo, 'build',
    '-Z', 'unstable-options',
    '--manifest-path', meson.current_source_dir() + '/Cargo.toml',
    '--release',
    '--out-dir', '@OUTDIR@',
    '--no-default-features',
    '--features', ' '.join(features),
  ],
  input: sources,
  output: ['bitvec.dll'],
  build_by_default: true,
)

bitvec_dep = declare_dependency(
  link_with: 'bitvec.dll',
)
