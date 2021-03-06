/* workflow local-blast{

    read-sequence {
        type:read-sequence;
        name:"Read sequence";
        url-in {
            dataset:"Dataset 1";
        }
    }
    blast {
        type:blast;
        name:"Local BLAST search";
    }
    write-genbank {y
        type:write-sequence;
        name:"Write Genbank";
        document-format:genbank;
    }


    .actor-bindings {
        read-sequence.out-sequence->blast.in-sequence
        blast.out-annotations->write-genbank.in-sequence
    }

    read-sequence.sequence->blast.in-sequence.sequence
    blast.annotations->write-genbank.in-sequence.annotations
    read-sequence.annotations->write-genbank.in-sequence.annotations
    read-sequence.sequence->write-genbank.in-sequence.sequence

    .meta {
        parameter-aliases {
            read-sequence.url-in {
                alias:in;
                description:"Input sequence";
            }
            blast.blast-output {
                alias:blast-out;
                description:"Type of BLAST output file";
            }
            blast.blast-type {
                alias:p;
                description:"Type of BLAST searches (using 'blastn' by default)";
            }
            blast.db-name {
                alias:dbname;
                description:"Base name for BLAST DB files";
            }
            blast.db-path {
                alias:dbpath;
                description:"Path with database files";
            }
            blast.e-val {
                alias:e;
                description:"The statistical significance threshold for reporting matches against database sequences (using '10.0' by default)";
            }
            blast.max-hits {
                alias:max-hits;
                description:"Specifies the number of best hits from a region of the query to keep. 0 turns it off. If used, 100 is recommended.";
            }
            blast.gapped-aln {
                alias:gap-aln;
                description:"Perform gapped alignment (using 'use' by default)";
            }
            blast.result-name {
                alias:name;
                description:"Name of the result annotations marking found regions (using 'blast_result' by default)";
            }
            blast.temp-dir {
                alias:tmpdir;
                description:"Directory to store temporary files (using UGENE temporary directory by default)";
            }
            blast.tool-path {
                alias:toolpath;
                description:"BLAST location (using the path specified in UGENE by default)";
            }
            blast.type-output {
                alias:out-type;
                description:"Type of BLAST output file (using 'XML (-m 7)' by default)";
            }
            write-genbank.accumulate {
                alias:accumulate;
                description:"Accumulate all incoming data in one file or create separate files for each input. In the latter case, an incremental numerical suffix is added to the file name (using 'True' by default)";
            }
            write-genbank.url-out {
                alias:out;
                description:"Output file with annotations";
            }
        }
        visual {
            blast {
                pos:"-600 -660";
                style:ext;
                bg-color-ext:"0 128 128 64";
                in-sequence.angle:180;
                out-annotations.angle:360;
            }
            read-sequence {
                pos:"-780 -660";
                style:ext;
                bg-color-ext:"0 128 128 64";
                out-sequence.angle:360;
            }
            write-genbank {
                pos:"-390 -660";
                style:ext;
                bg-color-ext:"0 128 128 64";
                in-sequence.angle:180;
            }
            blast.out-annotations->write-genbank.in-sequence {
                text-pos:"-33 -24";
            }
            read-sequence.out-sequence->blast.in-sequence {
                text-pos:"-27.5 -24";
            }
        }
    }
}
